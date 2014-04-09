the Instrument class controls specific components - its focused on the output end of the solarbots control panel

the Panel class receives inputs from the user - the user is plugging in wires that are mimicking power cables into specific power sections of the physical panel. The panel knows what those sections are and the user plugging in action tells the board what instrument the user desires to have that power. 

The arduino sketch loops through and asks these classes what it is to be done.