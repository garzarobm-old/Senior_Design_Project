import pyaudio
import sounddevice as sd

audio = pyaudio.PyAudio()


for i in range(audio.get_device_count()):
    dev = audio.get_device_info_by_index(i)
    print((i, dev))
    
    
print(sd.query_devices())