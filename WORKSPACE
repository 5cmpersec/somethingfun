workspace(name = "somethingfun")

new_local_repository(
    name = "sfml_hdrs",
    build_file = "third_party/sfml_hdrs.BUILD",
    path = "/usr/include/SFML",
)

new_local_repository(
    name = "sfml_lib",
    build_file = "third_party/sfml_lib.BUILD",
    path = "/lib/x86_64-linux-gnu/",
)

load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

new_git_repository(
    name = "ftxui",
    branch = "master",
    build_file = "//third_party:ftxui.BUILD",
    remote = "https://github.com/ArthurSonzogni/FTXUI.git",
)
