DESCRIPTION = "Task for a Parallella based image"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=3f40d7994397109285ec7b81fdeb3b58"

PR = "r1"

inherit packagegroup

RDEPENDS_${PN} = " \
	openssh \
	"
