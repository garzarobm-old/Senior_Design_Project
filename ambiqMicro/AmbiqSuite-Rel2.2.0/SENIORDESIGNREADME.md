$AMB_ROOT/boards : Here you can add custom definitions of the hardware or software capabilities of a given board that you might write code for - instead of having to manually include a custom header file all over the place. Ultimately this is where the SparkFun Edge Board Support Package will be placed.
$AMB_ROOT/CMSIS - This is a unified set of instructions for cortex processors.
$AMB_ROOT/mcu
apollo3
hal: Here you'll find the Ambiq interfaces for the hardware peripherals on the board.
$AMB_ROOT/tools
apollo3_scripts: Python scripts for making and transmitting update images
$AMB_ROOT/utils: Utilities that aren't related to hardware peripherals - delays, string operations, etc...




Having arrived here you should have all the components that you need to write an application for the Apollo3:

The SDK that contains useful source files and other definitions
An ARM compiler to translate your code into machine instructions
Make and a Bash shell to use to build the projects.
