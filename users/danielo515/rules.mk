SRC +=  danielo515.c \
        alt_tab.c \
		process_records.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards/
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tap_dance.c
endif
