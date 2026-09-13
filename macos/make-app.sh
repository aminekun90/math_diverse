#!/bin/bash
# Construit MathDiverse.app : le programme console de 2010-2014 dans une
# fenêtre macOS native.
#
# Deux étages : CMake produit le binaire, SwiftPM produit l'enveloppe
# SwiftTerm, et ce script les assemble en un bundle double-cliquable.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
APP="$ROOT/macos/MathDiverse.app"

# SwiftTerm embarque un shader Metal : le compilateur « metal » n'existe pas
# dans les Command Line Tools, il faut pointer sur Xcode.
export DEVELOPER_DIR="${DEVELOPER_DIR:-/Applications/Xcode.app/Contents/Developer}"

echo "==> Programme (CMake)"
cmake -S "$ROOT" -B "$ROOT/build" -DCMAKE_BUILD_TYPE=Release >/dev/null
cmake --build "$ROOT/build" >/dev/null

echo "==> Enveloppe (SwiftPM)"
swift build -c release --package-path "$ROOT/macos" >/dev/null

echo "==> Assemblage du bundle"
rm -rf "$APP"
mkdir -p "$APP/Contents/MacOS" "$APP/Contents/Resources"

cp "$ROOT/macos/.build/release/MathDiverseApp" "$APP/Contents/MacOS/MathDiverse"
cp "$ROOT/build/MathDiverse"                   "$APP/Contents/Resources/MathDiverse"
cp "$ROOT/tetris.wav" "$ROOT/a.xm"             "$APP/Contents/Resources/"

cat > "$APP/Contents/Info.plist" <<PLIST
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleName</key>            <string>MathDiverse</string>
    <key>CFBundleDisplayName</key>     <string>MathDiverse</string>
    <key>CFBundleIdentifier</key>      <string>dev.hellow.mathdiverse</string>
    <key>CFBundleExecutable</key>      <string>MathDiverse</string>
    <key>CFBundlePackageType</key>     <string>APPL</string>
    <key>CFBundleShortVersionString</key> <string>1.06</string>
    <key>CFBundleVersion</key>         <string>1.06</string>
    <key>LSMinimumSystemVersion</key>  <string>13.0</string>
    <key>NSHighResolutionCapable</key> <true/>
</dict>
</plist>
PLIST

codesign --force --deep --sign - "$APP" 2>/dev/null || true

echo "==> $APP"
