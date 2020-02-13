RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = yes
TAP_DANCE_ENABLE = yes
MOUSEKEY_ENABLE = no       # Mouse keys(+4700)
KEY_LOCK_ENABLE = no
COMBO_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
