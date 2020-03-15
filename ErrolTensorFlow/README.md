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
4. look at how micro_speech works
5. look at other tutorial
6. research the os
7. decide whether you have to create your own model or use their model


# attempt at retracing Errols steps

	Information known
		1.he trained a model on the collab and has followed tutorial to convert collab into code we can input into micro speech. (speech commands did something else, find out)
		2. he had to convert mp3 to wav files (I guess the model didn't want those types, pretty weird) 
		3. he trained some model and got 87.9 validation accuracy (find out what that means)
		4. find out what a neural network is
		5. see if we want to make a new model in ambiq or find some way to incorporate neural network.


# resources 
	1.  micro_speech tutorial in tensorflow/tensorflow/lite/micro/examples/micro_speech
			- Teaches you how to run a neural network to recognize speech words
				a. 20 kB neural network
				b. 10 kB of ram is used.
	2. the other tutorial *****TODO: FIND THE TUTORIAL8***

