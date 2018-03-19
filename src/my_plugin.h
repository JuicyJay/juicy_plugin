/*
 * my_plugin.h
 *
 *  Created on: Mar 15, 2018
 *      Author: phil
 */

#ifndef my_namespace__my_plugin_H
#define my_namespace__my_plugin_H

#include <rqt_gui_cpp/plugin.h>
#include <juicy_plugin/ui_my_plugin.h>
#include <QWidget>
#include <QPushButton>
namespace my_namespace {

class MyPlugin
  : public rqt_gui_cpp::Plugin
{
  Q_OBJECT
public:
  MyPlugin();
  virtual void initPlugin(qt_gui_cpp::PluginContext& context);
  virtual void shutdownPlugin();
  virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const;
  virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings);

  // Comment in to signal that the plugin has a way to configure it
  //bool hasConfiguration() const;
  //void triggerConfiguration();
private:
  Ui::my_plugin* ui_;
  QWidget* widget_;
  //QPushButton* _arscButton;
};
} // namespace
#endif // my_namespace__my_plugin_H


