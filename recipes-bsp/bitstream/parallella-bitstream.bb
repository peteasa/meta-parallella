SUMMARY = "Parallella Headless Bitstream"
SECTION = "bsp"

LICENSE = "GPLv3"
LIC_FILES_CHKSUM = "file://COPYING;md5=3c34afdc3adf82d2448f12715a255122"

SRC_URI = "git://github.com/parallella/parallella-hw.git;protocol=https"
SRCREV = "ce97134bc01e8f3b8374e0e74b2ca191c8873f59"

S = "${WORKDIR}/git"

INHIBIT_DEFAULT_DEPS = "1"
PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "parallella"

inherit deploy

do_compile() {
	:
}

do_install() {
	:
}

do_deploy() {
	install -d ${DEPLOY_DIR_IMAGE}/bitstreams
	for i in $(ls ${S}/fpga/bitstreams/ | grep parallella_.*_headless.*\.bit\.bin); do
		install ${S}/fpga/bitstreams/$i ${DEPLOY_DIR_IMAGE}/bitstreams
	done
}
addtask deploy before do_build after do_install

