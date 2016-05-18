# Cyril - Live Coding

**CMake:** This is the CMake branch that has been created for the cross-platform efforts.
Hopefully, by using ideas from [this example project](https://github.com/judepereira/44a) we
will be able to use CMake to build oF and Cyril.

The Cyril programming language is designed for fast prototyping of visualisations and live coding visuals.

Full information on the website:

 * http://cyrilcode.com

## Getting Started

The language reference on the website is slightly out-of-date. There's a website by Cyril user Dan Hett called [Cyril Patterns](http://cyrilpatterns.tumblr.com/) that has loads of examples, and is a good way to learn the syntax.

If you use a recent beta, then Post Processing effects are turned on by default, and can be toggled by pressing `cmd` + `z`. If you are not using post processing effects you probably want to toggle them off as the output quality improves.

See here for more [keyboard controls](http://cyrilcode.com/controls.html)

External editor support has been added in recent beta versions so you can project one screen and edit code in another using any text editor. Edit the files in the `data/code` folder and Cyril will refresh each time a file is saved.

## Requirements

Cyril is built against version 0.8.4 of openFrameworks

 * http://www.openframeworks.cc/download/

It also depends on various ofx Addons:

 * https://github.com/darrenmothersele/ofxBeat
 * https://github.com/darrenmothersele/ofxEditor
 * https://github.com/bakercp/ofxIO
 * ofxPostProcessing use my fork for extra getters/setters of params: https://github.com/darrenmothersele/ofxPostProcessing originally by Neil Mendoza https://github.com/neilmendoza/ofxPostProcessing

These addons may be required or will be dependencies soon as they are being used in new features:

 * ofxSyphon
 * ofxGUI
 * ofxOSC
 * ofxXmlSettings
