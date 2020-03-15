# Summary (pulled from Android Studio forum)

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
				
