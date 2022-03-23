FROM qmkfm/base_container

# Clone Git package
RUN git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git /qmk_firmware

# Set the default location for qmk_firmware
ENV QMK_HOME /qmk_firmware
WORKDIR /qmk_firmware