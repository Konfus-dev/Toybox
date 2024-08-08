#include "Interop.h"
#include "InteropApp.h"
#include <gl/GL.h>

namespace Toybox::Interop
{
    void InteropApp::OnOpen()
    {
        TBX_TRACE("OnOpen called!");
    }

	float _red = 1;
	float _green = 0.5f;
	float _blue = 0;
    void InteropApp::OnUpdate()
    {
		// TESTING CODE!
		{
			glClearColor(_red, _green, _blue, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			if (_red > 1)
				_red = 0;
			if (_red < 0)
				_red = 1;

			if (_green > 1)
				_green = 0;
			if (_green < 0)
				_green = 1;

			if (_blue > 1)
				_blue = 0;
			if (_blue < 0)
				_blue = 1;

			_red += 0.01f;
			_green += 0.01f;
			_blue += 0.01f;
		}

        _frameCount++;
    }

    void InteropApp::OnClose()
    {
        TBX_TRACE("OnClose called!");
    }
}