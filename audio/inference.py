import librosa
import numpy as np
import os
import pickle
import xgboost as xgb
import pandas as pd
import time
import requests

import warnings
warnings.filterwarnings('ignore')

# load model
version = 1
model = pickle.load(open('model-{}.pickle'.format(version), "rb"))
cols = model.feature_names

while(1):
    # record 5 seconds of audio
    print('recording 5 seconds of audio')
    os.system('arecord -d 5 -D "sysdefault:CARD=Device" output.wav')
    #time.sleep(5)
    print('done recording')
    x, sr = librosa.load('output.wav')
    rmse = np.mean(librosa.feature.rmse(y=x))
    zcr = np.mean(librosa.feature.zero_crossing_rate(y=x))
    mfcc = np.mean(librosa.feature.mfcc(y=x, sr=sr, n_mfcc=1))
    onset_env = librosa.onset.onset_strength(x, sr=sr)
    tempo = librosa.beat.estimate_tempo(onset_env, sr=sr)
    pred_data = {
            'rmse': [rmse],
            'zcr': [zcr],
            'mfcc': [mfcc],
            'tempo': [tempo]
            }
    df = pd.DataFrame(data=pred_data)
    df = df[cols]
    dpred = xgb.DMatrix(df)
    prediction = model.predict(dpred)[0]

    # pred_name = Null
    pred_name = 'music'     
    weburl = 'https://socialbitapi.appspot.com/user/Music'
    data = {'name': 'Music', 'result': 1}

    if prediction == 1:
        pred_name = 'noise'
        weburl = 'https://socialbitapi.appspot.com/user/Noise'
        data = {'name': 'Noise', 'result': 1}
    elif prediction == 2:
        pred_name = 'speech'
        weburl = 'https://socialbitapit.appspot.com/user/Speech'
        data = {'name': 'Speech', 'result': 1}

    
    #elif prediction == 0:
    #    pred_name = 'music'
    r = requests.post(url = weburl, data = data)
    print('Predicted last 5 seconds was {}'.format(pred_name)) 
