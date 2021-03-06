# Copyright (C) 2008 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# definitions shared by host_executable.make and host_static_library.make
#

# the directory where we're going to place our object files
LOCAL_OBJS_DIR  := $(call intermediates-dir-for,EXECUTABLES,$(LOCAL_MODULE))
LOCAL_OBJECTS   :=
LOCAL_CC        ?= $(CC)
LOCAL_C_SOURCES := $(filter  %.c,$(LOCAL_SRC_FILES))
LOCAL_OBJC_SOURCES := $(filter %.m,$(LOCAL_SRC_FILES))

$(foreach src,$(LOCAL_C_SOURCES), \
    $(eval $(call compile-c-source,$(src))) \
)

$(foreach src,$(LOCAL_OBJC_SOURCES), \
    $(eval $(call compile-objc-source,$(src))) \
)

CLEAN_OBJS_DIRS += $(LOCAL_OBJS_DIR)
