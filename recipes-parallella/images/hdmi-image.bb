#
# Parallella hdmi Image
#
SUMMARY = "An image that provides a complete build environment for working with the Epiphany co-processor"
LICENSE = "MIT"
DESCRIPTION = "Parallella hdmi Image"

PR="r1"

inherit core-image

IMAGE_FEATURES += "ssh-server-openssh"

IMAGE_INSTALL = " \
		packagegroup-core-boot \
		${CORE_IMAGE_EXTRA_INSTALL} \
		packagegroup-core-buildessential \
		packagegroup-epiphany-elf-buildessentialfromsource \
		packagegroup-epiphany-sdk-buildessentialfromsource \
		git \
		"

IMAGE_INSTALL += "\
	strace \
	ldd \
	gdbserver \
	lighttpd \
	bash \
    sudo \
    "
IMAGE_FEATURES += "package-management"

# Inherit the core-image (Causes core-image to be built)
inherit core-image

# Specify to write image as a tar.gz file
IMAGE_FSTYPES = "tar.gz"

# Install kernel-modules and capability to build modules
IMAGE_INSTALL += " \
    kernel-modules \
    kmod \
"

# Add kernel-dev to the image so that modules can be built on target
IMAGE_INSTALL += " \
	kernel-dev \
	kernel-devsrc \
"

# for debugging could also add systemtap
IMAGE_INSTALL += " \
    dtc \
    i2c-tools \
    devmem2 \
"

# populate the sdk with epiphany-elf-* tools
TOOLCHAIN_HOST_TASK += "\
    packagegroup-nativesdk-epiphany-elf-buildessentialfromsource \
    packagegroup-nativesdk-epiphany-sdk-buildessentialfromsource \
"
