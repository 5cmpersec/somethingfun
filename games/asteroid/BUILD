load("@rules_cc//cc:defs.bzl", "cc_binary")

filegroup(
    name = "resources",
    srcs = ["res"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "asteroid",
    srcs = [
        "Animator.cpp",
        "Animator.hpp",
        "AssetManager.cpp",
        "AssetManager.hpp",
        "Asteroid.cpp",
        "Asteroid.hpp",
        "Explosion.cpp",
        "Explosion.hpp",
        "Game.cpp",
        "Game.hpp",
        "SpaceShip.cpp",
        "SpaceShip.hpp",
        "main.cpp",
    ],
    data = [":resources"],
    env = {
        "RESOURCES_DIR": "$(location :resources)",
    },
    visibility = [
        "//visibility:public",
    ],
    deps = [
        "@sfml_hdrs//:graphics",
        "@sfml_hdrs//:system",
        "@spdlog"
    ],
)
