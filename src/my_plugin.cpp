/*
 * my_plugin.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: phil
 */


#include "my_plugin.h"
#include <pluginlib/class_list_macros.h>
#include <QStringList>
#include <QDebug>


namespace my_namespace {

MyPlugin::MyPlugin():
		rqt_gui_cpp::Plugin(),
  widget_(0),
  ui_(NULL)
{
  // Constructor is called first before initPlugin function, needless to say.

  // give QObjects reasonable names
  setObjectName("MyPlugin");
}

void MyPlugin::initPlugin(qt_gui_cpp::PluginContext& context)
{
//	qDebug() << __PRETTY_FUNCTION__;
//  // access standalone command line arguments
  QStringList argv = context.argv();
  ui_ = new Ui::my_plugin;
//  // create QWidget
  widget_ = new QWidget();
//  // extend the widget with all attributes and children from UI file
  ui_->setupUi(widget_);
//  _arscButton = new QPushButton(widget_);
//  _arscButton->show();
//  // add widget to the user interface
  context.addWidget(widget_);
//  qDebug() << __PRETTY_FUNCTION__ << " end";
}

void MyPlugin::shutdownPlugin()
{
  // TODO unregister all publishers here
}

void MyPlugin::saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const
{
  // TODO save intrinsic configuration, usually using:
  // instance_settings.setValue(k, v)
}

void MyPlugin::restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings)
{
  // TODO restore intrinsic configuration, usually using:
  // v = instance_settings.value(k)
}

/*bool hasConfiguration() const
{
  return true;
}

void triggerConfiguration()
{
  // Usually used to open a dialog to offer the user a set of configuration
}*/

} // namespace
PLUGINLIB_DECLARE_CLASS(my_namespace, MyPlugin, my_namespace::MyPlugin, rqt_gui_cpp::Plugin)
