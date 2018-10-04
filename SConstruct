# Copyright (c) 2017-2018, Niklas Hauser
#
# This file is part of the modm project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

#!/usr/bin/env python3

import os
from os.path import join, abspath

# User Configurable Options
project_name = "blink"
build_path = "../../../build/stm32f429_discovery/blink"
generated_paths = ['modm']

# SCons environment with all tools
env = Environment(ENV=os.environ)
env["CONFIG_BUILD_BASE"] = abspath(build_path)
env["CONFIG_PROJECT_NAME"] = project_name

# Building all libraries
env.SConscript(dirs=generated_paths, exports="env")

env.Append(CPPPATH=".")
ignored = ["cmake-*", ".lbuild_cache", build_path] + generated_paths
sources = []
# Finding application sources
sources += env.FindSourceFiles(".", ignorePaths=ignored)
env.BuildTarget(sources)