// Copyright (c) 2020 The Orbit Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ORBITQT_ORBIT_STARTUP_WINDOW_H_
#define ORBITQT_ORBIT_STARTUP_WINDOW_H_

#include <QDialog>
#include <QPointer>
#include <QWidget>
#include <optional>

#include "OrbitGgp/GgpClient.h"
#include "OrbitGgp/GgpInstance.h"
#include "OrbitGgp/GgpInstanceItemModel.h"
#include "OrbitGgp/GgpSshInfo.h"

class OrbitStartupWindow : public QDialog {
 public:
  explicit OrbitStartupWindow(QWidget* parent = nullptr);

  template <typename Credentials>
  int Run(Credentials* credentials) {
    int dialog_result = exec();

    if (dialog_result != 0) {
      credentials->host = ssh_info_->host.toStdString();
      credentials->key_path = ssh_info_->key_path.toStdString();
      credentials->known_hosts_path = ssh_info_->known_hosts_path.toStdString();
      credentials->user = ssh_info_->user.toStdString();
      credentials->port = ssh_info_->port;
    }
    return dialog_result;
  }

 private:
  void ReloadInstances();

  std::optional<GgpClient> ggp_client_;
  std::optional<GgpInstance> chosen_instance_;
  std::optional<GgpSshInfo> ssh_info_;
  QPointer<GgpInstanceItemModel> model_;
};

#endif  // ORBITQT_ORBIT_STARTUP_WINDOW_H_