SECTION = "bsp"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${WORKDIR}/LICENSE;md5=a6a9379d3abeee2cd13eef007e9324fd"

PV = "y2024.2"
TAG = "parallella-2024.2-rc1"
BASE_URL = "https://github.com/peteasa/oh/releases/download/${TAG}"

SRC_URI = "https://raw.githubusercontent.com/peteasa/oh/y2024.2/LICENSE;name=license"
SRC_URI:append:parallella = " \
    ${BASE_URL}/parallella_e16_headless_gpiose_7010.dtb;name=headless-z7010 \
    ${BASE_URL}/parallella_e16_headless_gpiose_7020.dtb;name=headless-z7020 \
"
SRC_URI:append:parallella-hdmi = " \
    ${BASE_URL}/parallella_e16_hdmi_gpiose_7010.dtb;name=hdmi-z7010 \
    ${BASE_URL}/parallella_e16_hdmi_gpiose_7020.dtb;name=hdmi-z7020 \
"

SRC_URI[license.sha256sum]        = "6547723dd941be2cca0b3ea7cc2a9d484de3d3a78b3620062d9538c071317b79"
SRC_URI[headless-z7010.sha256sum] = "0ee4da55dc86ca9710eada9b95a27de2503b78466fd2283b8bfd79a56bec6d1a"
SRC_URI[headless-z7020.sha256sum] = "0ee4da55dc86ca9710eada9b95a27de2503b78466fd2283b8bfd79a56bec6d1a"
SRC_URI[hdmi-z7010.sha256sum]     = "92059ecdca35b2be0800615341fec53abdb854b462e1264c3118dd77d868a365"
SRC_URI[hdmi-z7020.sha256sum]     = "92059ecdca35b2be0800615341fec53abdb854b462e1264c3118dd77d868a365"

INHIBIT_DEFAULT_DEPS = "1"
PACKAGE_ARCH = "${MACHINE_ARCH}"

DEPENDS += "virtual/kernel"

inherit deploy

do_compile() {
	:
}

do_install() {
	:
}

DEVICETREE_PATTERN:parallella = "parallella_*headless*.dtb*"
DEVICETREE_PATTERN:parallella-hdmi = "parallella_*hdmi*.dtb*"

normalize_dtb () {
	dtb="$1"
	if echo $dtb | grep -q '/dts/'; then
		bbwarn "$dtb contains the full path to the the dts file, but only the dtb name should be used."
		dtb=`basename $dtb | sed 's,\.dts$,.dtb,g'`
	fi
	echo "$dtb"
}

do_deploy() {
	install -d ${DEPLOYDIR}
	for i in ${WORKDIR}/${DEVICETREE_PATTERN}; do
		install ${i} ${DEPLOYDIR}
		for dtbf in ${KERNEL_DEVICETREE}; do
			dtb=`normalize_dtb "$dtbf"`
			# can handle dtb or dtbo files
			dtb_ext=${dtb##*.}
			dtb_base_name=`basename $dtb .$dtb_ext`
			srcfn_ext=${i##*.}
			srcfn=`basename "${i}" .$srcfn_ext`
			# demonstrate how to handle multiple versions - in the simple case 7010 and 7020 are the same devicetree
			srcnum=${srcfn##*_}
			echo srcnum: $srcnum
			ln -rsf ${DEPLOYDIR}/$srcfn.$srcfn_ext ${DEPLOYDIR}/${dtb_base_name}_$srcnum.$dtb_ext
		done
	done
}
addtask deploy before do_build after do_install
