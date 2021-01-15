[![license](https://img.shields.io/github/license/micro-os-plus/libs-cpp-estd-xpack)](https://github.com/micro-os-plus/libs-cpp-estd-xpack/blob/xpack/LICENSE)

# A source xPack with Embedded `std::` support

This project includes files that complement the C++ `std::` classes.

This README is intended to developers who plan to include this package
in their own projects.

For maintainer infos, please see the [README-MAINTAINER](README-MAINTAINER.md) file.

## Easy install

This package is available as
[`@micro-os-plus/libs-cpp-estd`](https://www.npmjs.com/package/@micro-os-plus/libs-cpp-estd)
from the `npmjs.com` registry; with [xpm](https://xpack.github.io/xpm/)
available, installing the latest version of the package is quite easy:

```console
$ xpm install @micro-os-plus/libs-cpp-estd@latest
```

This package is also available from
[GitHub](https://github.com/micro-os-plus/libs-cpp-estd-xpack):

```console
$ git clone https://github.com/micro-os-plus/libs-cpp-estd-xpack.git libs-cpp-estd-xpack.git
```

## Branches

Apart from the unused `master` branch, there are three active branches:

- `xpack`, with the latest stable version
- `xpack-develop`, with the current development version
- `originals`, with 3rd party original code (optional)

All development is done in the `xpack-develop` branch, and contributions via
Pull Requests should be directed to this branch.

When new releases are published, the `xpack-develop` branch is merged
into `xpack`.

## User info

The new classes are defined in the `os::estd` namespace. Having them
in a separate namespace allows to run tests on the synthetic POSIX platform.

Since the libraries included in the current embedded toolchain do not
include support for threads, it is possible to also define 
the same functionality in the `std::` namespace, and reuse
source code from POSIX desktops.

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT), with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul).
