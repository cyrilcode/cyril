# ofxEditor

A simple text editor for openFrameworks for live coding. Features multiple
text buffers and the ability to define custom commands.

## Usage

Add to your openFrameworks project and initialize an editor variable passing
in the number of text buffers you require (defaults to 1). For example:

    class testApp : public ofBaseApp{

      ofxEditor editor;
      bool editorVisible;

    public:
      testApp() : editor(9) {}

      // Editor command callbacks are static methods
      static void toggleEditor(void *);

      // ... rest of your oF app ...

    };

You can define custom commands in your setup function, for example:

    void testApp::setup(){
      editor.addCommand('a', this, &testApp::toggleEditor);
    }

    void testApp::toggleEditor(void * _o) {
      ((testApp *)_o)->editorVisible = !((testApp *)_o)->editorVisible;
    }

To get the current text in the editor you need to reference the `getText()`
method of the current buffer.

    editor.buf[editor.currentBuffer]->getText();

For the editor to be visible you need to draw it in your main oF app draw loop:

    if (editorVisible) {
      editor.draw();
    }


## Limitations

The code includes a workaround for a bug in GLFW as mentioned here:
https://github.com/openframeworks/openFrameworks/issues/2562

The clipboard code only works on OSX.

