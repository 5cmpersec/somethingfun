filegroup(
    name = "asteroid",
    srcs = [
        "//games/asteroid",
    ],
    visibility = ["//visibility:public"],
)

load("@com_grail_bazel_compdb//:aspects.bzl", "compilation_database")

compilation_database(
    name = "compdb",
    targets = [
        "//games/asteroid",
    ],
)