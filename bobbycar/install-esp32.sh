sudo usermod -a -G dialout $USER && \
sudo apt-get -y install git && \
wget https://bootstrap.pypa.io/get-pip.py && \
pip install --user pyserial && \
mkdir -p ~/Arduino/hardware/espressif && \
cd ~/Arduino/hardware/espressif && \
git clone https://github.com/espressif/arduino-esp32.git esp32 && \
cd esp32 && \
git submodule update --init --recursive && \
cd tools && \
python get.py
