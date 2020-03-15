# Summary of GATT (pulled from Android Studio forum)

# Generic Attribute Profile (GATT)
	The profile we are concerned with.
# Attribute Protocol (ATT)
	The protocol we are concerned with
# Characteristic
	I believe it is the fancy name for the 'value' we receive.
		- single value
		- latched with descriptors (defined below)
# Descriptor
	They just describe the characteristic
		- will be human readable 
		- Probably say String or Number, with an acceptable range (length = 8, blah blah)
		- have a unit of measurement (%, number, 8bit, 6bit)
# Service 
	Realistically, they are only a set of characteristics.
		-Example:
				Heart rate profile		 -> service
				Heart rate measurement   -> characteristic

# TODO
	1. make a connection (CENTRAL VS. PERIPHERAL)
	2. talk to each other (GATT server vs. GATT client)


# Android Studio project I made
	1. made a starter project with a basic activity
		A. Main activity that controls a floating action bar and toolbar
		B. First Fragment that has a text and a button (uses nav_graph.xml) to move to the second fragment
		C. Second Fragment that mimics First Fragment
	2. researched some basic GATT protocol data transfers
	3. I stopped here. 
