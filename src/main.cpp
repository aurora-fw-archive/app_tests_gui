/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU General Public License version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE included in the
** packaging of this file. Please review the following information to
** ensure the GNU General Public License version 3 requirements will be
** met: https://www.gnu.org/licenses/gpl-3.0.html.
****************************************************************************/

#include <AuroraFW/Aurora.h>

using namespace AuroraFW;

GUI::Application *MyGUIApp;
GUI::Window *FirstWindow;
GUI::Label *HelloLabel;
GUI::Button *TestButton;

ArSlot_t slot_MyWindow_on_open()
{
	HelloLabel->setText("Hello, World!");
	HelloLabel->setSelectable(true);
	HelloLabel->setWrap(true);
	HelloLabel->setWrapMode(GUI::WrapMode::Word);
	HelloLabel->setAlignment(GUI::AlignMode::Custom);
	HelloLabel->setAlignment(0.7, 0.8);
	GUI::AlignMode alignLabel = HelloLabel->getAlignment();
	CLI::Log(CLI::Information,"X: ", HelloLabel->getXAlignment());
	CLI::Log(CLI::Information,"Y: ", HelloLabel->getYAlignment());
}

ArSlot_t slot_MyGUIApp_on_open()
{
	FirstWindow = new GUI::Window("First Window", 800, 600, GUI::Window::NonePosition, GUI::Window::ToplevelWindow);
	TestButton = new GUI::Button(FirstWindow, "TestButton");
	HelloLabel = new GUI::Label(FirstWindow, "Hello World!");
	FirstWindow->start(slot_MyWindow_on_open);
}

int main(int argc, char * argv[])
{
	MyGUIApp = new GUI::Application("org.aurora.example", GUI::Application::NoneFlag, slot_MyGUIApp_on_open, argc, argv);
	return MyGUIApp->AppStatus;
}
