# what we know:


1. we can load a model onto the ambiq that was trained on the google collab
2. there are models that already extract certain speech commands on the ambiq like 'yes' 'no' on the ambiq, maybe we can change that one up a little to get the patterns we want



# What we want to do:

1. incorporate the features onto the os that we currently have.
2. get real-time inferencing to be good rather than bad



# Steps

1. catch up with what machine learning team currently has;;;; MOSTLY DONE
2. see if you can load the old code into the ambiq;;;;; DONE
3. see if you can train some data into model yourself;;;; DOING NOW
4. look at how micro_speech works in MICRO ;; almost done -> stopped at train your own model 
5. https://github.com/tensorflow/docs/blob/master/site/en/r1/tutorials/sequences/audio_recognition.md speech_commands ;; almost done... -> stopped at how does this model work?
6. research the os  ;; started
7. decide whether you have to create your own model or use their model	;; decided!
8. Find out if you can actually start importing you c code onto the project. Tutorial -> stopped at getting Started

# attempt at retracing Errols steps

	Information known
		1.he trained a model on the collab (SocialBitTest1) and has followed tutorial to convert collab into code we can input into micro speech. (speech commands did something else, find out)
		2. he had to convert mp3 to wav files (MP3 Conversion) 
		3. he used the current model and converted to Ambiq code (Ambiq)
		3. he trained some model and got 87.9 validation accuracy (find out what that means)
		4. find out what a neural network is
		5. see if we want to make a new model in ambiq or find some way to incorporate neural network.


# resources 
	1.  micro_speech tutorial in tensorflow/tensorflow/lite/micro/examples/micro_speech
			- Teaches you how to run a neural network to recognize speech words
				a. 20 kB neural network
				b. 10 kB of ram is used.
			- has already a set of "yes, no" words you can train.
	2. Speech_commands tutorial for training 7 words
	3. We could try other options instead of the CNN
			A. recurrent network
			B.dilate (atrous) convolutions.




# what our machine learning model needs
	1. an operating system
	2. C or C++ standard libraries
	3. dynamic memory allocation
	4. Floating point
	5. debugLog() <--- I have no idea what this is <<-- UPDATE: It is just UART!

# current TensorFlow examples

	USEFUL	1. micro speech - For Use of neural networks
	USEFUL	2. Speech Commands - For recognizing words NOTE*** MAYBE DEVELOP FOR more words???
	NOT		3. person detection - For recognizing people with a camera - probably not use
	USEFUL	4. network_tester - for testing our model
	USEFUL	5. magic_wand - for using an acceleratamotor
	MAYBE 	6. hello_world - for basics and use leds to control an animation


# ideas
	1. we could somehow build on top of the speech Commands dataset, if we hear any of these words, then it is speech. Otherwise noise or music.... hmmm, how would it not register as music?

# comments as I am training my own stuff

	1. are we saving 10% for validation, 80% for training, and 10% for testing? Answer: I think the training script does this with all our data.
	2. our own data? (3 weeks) x (2 days)x((180 minutes) - (60 categorization) )/(5 minute clips) = 144 5 minute clips of our own data

