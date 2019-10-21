import numpy as np

import pyaudio
import wave
import collections
import time
import threading
import datetime
import os

def save_recording_v2():
    thread = threading.Thread(target=write_to_file, args=())
    thread.start()
    
def write_to_file():
    time.sleep(20)
    
    folder = datetime.datetime.now().strftime('%y-%m-%d')
    wav_output_filename = datetime.datetime.now().isoformat()[:-7] + '.wav'
    wav_output_filename = wav_output_filename.replace(":","-")
    if not os.path.exists(folder):
        os.makedirs(folder,0o777)
    path = "./" + folder + "/" + wav_output_filename
    data = FIFObuffer.copy()
    print(path)
    wavefile = wave.open(path, 'wb')
    wavefile.setnchannels(chans)
    wavefile.setsampwidth(audio.get_sample_size(form_1))
    wavefile.setframerate(samp_rate)
    wavefile.writeframes(b''.join(data))
    wavefile.close()
    print("done")

def continuous_recorder(in_data, frame_count, time_info, status):
    global FIFObuffer
    FIFObuffer.append(in_data)
    return in_data, pyaudio.paContinue

form_1 = pyaudio.paInt16
#chans = 1
chans = 8
#samp_rate = 44100
samp_rate = 16000
#chunk = 4096
chunk = 1024
record_secs = 30
dev_index = 2
save_to_file = False
FIFObuffer = collections.deque([b"0"*2*chans*chunk]*int(samp_rate/chunk)*record_secs, maxlen=int(samp_rate/chunk)*record_secs)

audio = pyaudio.PyAudio()
stream = audio.open(format = form_1, rate = samp_rate, channels = chans, \
                        input_device_index = dev_index, input = True, \
                        frames_per_buffer = chunk, stream_callback = continuous_recorder)

time.sleep(60)
save_recording_v2()

