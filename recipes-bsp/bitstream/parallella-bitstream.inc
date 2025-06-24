SECTION = "bsp"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${WORKDIR}/LICENSE;md5=a6a9379d3abeee2cd13eef007e9324fd"

PV = "y2024.2"
TAG = "parallella-2024.2-rc1"
BASE_URL = "https://github.com/peteasa/oh/releases/download/${TAG}"

SRC_URI = "https://raw.githubusercontent.com/peteasa/oh/y2024.2/LICENSE;name=license"
SRC_URI:append:parallella = " \
    ${BASE_URL}/parallella_e16_headless_gpiose_7010.bit.bin;name=headless-z7010 \
    ${BASE_URL}/parallella_e16_headless_gpiose_7020.bit.bin;name=headless-z7020 \
"
SRC_URI:append:parallella-hdmi = " \
    ${BASE_URL}/parallella_e16_hdmi_gpiose_7010.bit.bin;name=hdmi-z7010 \
    ${BASE_URL}/parallella_e16_hdmi_gpiose_7020.bit.bin;name=hdmi-z7020 \
"

SRC_URI[license.sha256sum]        = "6547723dd941be2cca0b3ea7cc2a9d484de3d3a78b3620062d9538c071317b79"
SRC_URI[headless-z7010.sha256sum] = "58ee7ef496c76db5feb01a3b5923ad87ad334c42f17305b69a6e8b612e993938"
SRC_URI[headless-z7020.sha256sum] = "f92d1718fcb9e936bfc521e191c80025e78ed43adaf4bb1732e4e70c68f4f0cb"
SRC_URI[hdmi-z7010.sha256sum]     = "df09f5f4e3cf39cbcff82205e7fe72f5cb7ddf06f0e1a9a59547b4a8546483de"
SRC_URI[hdmi-z7020.sha256sum]     = "9a1d5dfb2b2d67cb5293abea2bc885801b71c31999b3108ff9910b26f28dc262"

INHIBIT_DEFAULT_DEPS = "1"
PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit deploy

do_compile() {
	:
}

do_install() {
	:
}

BITSTREAM_PATTERN:parallella = "parallella_*headless_*.bit.bin"
BITSTREAM_PATTERN:parallella-hdmi = "parallella_*hdmi_*.bit.bin"

do_deploy() {
	install -d ${DEPLOYDIR}/bitstreams
	for i in ${WORKDIR}/${BITSTREAM_PATTERN}; do
		install ${i} ${DEPLOYDIR}/bitstreams
	done
}
addtask deploy before do_build after do_install
