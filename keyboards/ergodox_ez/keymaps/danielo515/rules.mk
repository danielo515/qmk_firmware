# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
EXTRAFLAGS += -flto
AUTO_SHIFT_ENABLE = no
TAP_DANCE_ENABLE = yes # Enable the tap dance feature.
LEADER_ENABLE = yes
CONSOLE_ENABLE = no
RGBLIGHT_ENABLE = yes
DEBOUNCING_TYPE = sym_g
