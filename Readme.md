Candle 2
-----------
GRBL and GRBL-Advanced controller application with G-Code visualizer written in Qt.
Forked from [Schildkroet/Candle2](https://github.com/Schildkroet/Candle2)

Supported functions:
* Controlling GRBL-based CNC-Machine via console commands, buttons on form and numpad.
* Monitoring cnc-machine state.
* Loading, editing, saving and sending of G-code files to CNC-Machine.
* Visualizing G-code files.

System requirements for running "Candle2":
-------------------
* Windows/Linux x86_x64
* CPU with SSE2 instruction set support
* Graphics card with OpenGL 2.0 support
* 160 MB free storage space

Build requirements:
------------------
Windows: Qt 5.15.2 with MinGW/GCC compiler

Linux: QT 5.12.2 with GCC

## How to Build on Debian derivatives

- Install QT5 & other pre-requirements
  `sudo apt-get install -y cmake g++ make qtbase5-dev qtscript5-dev qttools5-dev qttools5-dev-tools libqt5serialport5-dev libqt5opengl5-dev qtmultimedia5-dev libqt5multimediawidgets5 libqt5multimedia5-plugins libqt5multimedia5 libqt5designercomponents5 libqt5designer5 qtcreator`  

- Clone candle2
  ```git clone https://github.com/pflagerd/candle2.git```

- Build candle2

  `# Please don't be alarmed by warnings during the build.`

  `cd candle`/src

  `qmake `

  `make` -j 16

* The last lines of the successful build should look something like this:

  ````
  ```
  g++ -c -pipe -O2 -std=gnu++11 -Wall -Wextra -D_REENTRANT -fPIC -DUNIX -DsNan="65536" -DAPP_VERSION=\"1.1.8\" -D_USE_MATH_DEFINES -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_SERIALPORT_LIB -DQT_CORE_LIB -I. -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtOpenGL -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I. -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -o moc_sliderbox.o moc_sliderbox.cpp
  g++ -Wl,-rpath,'$ORIGIN/libs' -Wl,-O1 -o Candle main.o frmmain.o frmsettings.o frmabout.o gcodedrawer.o heightmapborderdrawer.o heightmapgriddrawer.o heightmapinterpolationdrawer.o origindrawer.o shaderdrawable.o tooldrawer.o arcproperties.o gcodeparser.o gcodepreprocessorutils.o gcodeviewparse.o linesegment.o pointsegment.o gcodetablemodel.o heightmaptablemodel.o colorpicker.o combobox.o groupbox.o scrollarea.o styledtoolbutton.o widget.o glwidget.o slider.o sliderbox.o selectiondrawer.o comboboxkey.o qrc_shaders.o qrc_images.o moc_frmmain.o moc_frmsettings.o moc_frmabout.o moc_gcodedrawer.o moc_gcodeparser.o moc_gcodepreprocessorutils.o moc_gcodeviewparse.o moc_gcodetablemodel.o moc_heightmaptablemodel.o moc_colorpicker.o moc_combobox.o moc_groupbox.o moc_scrollarea.o moc_widget.o moc_glwidget.o moc_slider.o moc_sliderbox.o   /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5SerialPort.so /usr/lib/x86_64-linux-gnu/libQt5Core.so -lGL -lpthread 
  ```
  ````

- Launch Candle
  `./candle`

* You should see something like this:

  ![screenshot](Screenshots/image1.png)

Downloads:
----------
* Releases (Win & Linux): [Candle 2](https://github.com/pflagerd/candle2/releases)

