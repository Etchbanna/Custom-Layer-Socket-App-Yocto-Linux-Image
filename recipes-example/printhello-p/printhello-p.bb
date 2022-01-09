DESCRIPTION = "UDP Sending Packet"
PRIORITY = "optional"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI = "file://udp_send.c"
S = "${WORKDIR}"
do_compile() {
${CC} ${CFLAGS} ${LDFLAGS} udp_send.c -o UDPsend
}
do_install() {
install -d ${D}${bindir}
install -m 0755 UDPsend ${D}${bindir}
}
