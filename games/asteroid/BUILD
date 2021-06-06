load("@rules_cc//cc:defs.bzl", "cc_binary")

filegroup(
    name = "resources",
    srcs = ["res"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "asteroid",
    srcs = [
        "Asteroid.cpp",
        "SpaceShip.cpp",
        "Game.cpp",
        "main.cpp",
        "Explosion.cpp",
        "Animator.cpp",
        "AssetManager.cpp",
        "Explosion.hpp",
        "Asteroid.hpp",
        "Animator.hpp",
        "Game.hpp",
        "AssetManager.hpp",
        "SpaceShip.hpp",
    ],
    visibility = [
        "//visibility:public",
    ],
    data = [":resources"],
    deps = [
        "@sfml_hdrs//:graphics",
        "@sfml_hdrs//:system",
    ],
    env = {
        "RESOURCES_DIR": "$(location :resources)",
    },
)
