// swift-tools-version: 5.9
import PackageDescription

// Enveloppe SwiftUI pour MathDiverse, programme console de 2010-2014.
//
// Le programme reste ce qu'il est : un binaire terminal. SwiftTerm fournit un
// émulateur de terminal natif dans lequel on le lance, ce qui donne une
// vraie fenêtre macOS — sans réécrire une ligne de C++.
let package = Package(
    name: "MathDiverseApp",
    platforms: [.macOS(.v13)],
    dependencies: [
        .package(url: "https://github.com/migueldeicaza/SwiftTerm", from: "1.2.0")
    ],
    targets: [
        .executableTarget(
            name: "MathDiverseApp",
            dependencies: ["SwiftTerm"]
        )
    ]
)
