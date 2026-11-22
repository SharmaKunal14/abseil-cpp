# Native baseline for Smart CI evaluation

Source pin: 82530019412ff77ff99d39ba0ad12e5ea6b89ea4.

This isolated fork branch preserves application code, build rules and native tests.
It runs the existing ci/linux_gcc-latest_libstdcxx_bazel.sh script with its
C++17 / fastbuild / no-exceptions profile. The optional private remote cache is
unavailable and is not configured. Bazel test-result caching is not disabled.
The pinned upstream public Docker image, compilers and Bazel version are retained.

Only a Build Event Protocol output path and a unique container name are added
through upstream hooks. Results count Bazel test targets, not internal C++ test
cases. Native failures remain failures. Missing/truncated evidence is an error.

One GitHub-hosted Ubuntu job, maximum 25 minutes, 20-minute native-process limit,
seven-day artifacts, read-only repository permissions and no deployment workflow.
Initial baseline only: no Smart CI selection or performance benefit is claimed.
Upstream master remains unchanged. Do not merge experiment branches.

This PR establishes the unchanged native GitHub baseline before selection.
