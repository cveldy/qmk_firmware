COMBO_ENABLE = yes

# LTO: link time optimization makes the build take slightly longer
# but makes the resulting .hex file smaller, which allows you to
# fit more features into smaller MCUs:
LTO_ENABLE = yes

# Support for these features make the hex file larger, but we want 'em:
NKRO_ENABLE = yes
