/*
 *
 * Tencent is pleased to support the open source community by making
 * Hippy available.
 *
 * Copyright (C) 2019 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

#include <jni.h>
#include <stdint.h>

#include <memory>

#include "core/core.h"
#include "jni/turbo_module_runtime.h"
#include "jni/scoped_java_ref.h"

class Runtime {
 public:
  using Bridge = hippy::Bridge;
#ifndef V8_WITHOUT_INSPECTOR
  using V8InspectorContext = hippy::inspector::V8InspectorContext;
#endif
  Runtime(std::shared_ptr<Bridge> bridge, bool enable_v8_serialization, bool is_dev);

  inline bool IsEnableV8Serialization() { return enable_v8_serialization_; }
  inline bool IsDebug() { return is_debug_; }
  inline int32_t GetId() { return id_; }
  inline int64_t GetGroupId() { return group_id_; }
  inline std::shared_ptr<Bridge> GetBridge() { return bridge_; }
  inline std::shared_ptr<Engine> GetEngine() { return engine_; }
  inline std::shared_ptr<Scope> GetScope() { return scope_; }
  inline std::shared_ptr<hippy::napi::CtxValue> GetBridgeFunc() {
    return bridge_func_;
  }
  inline std::string& GetBuffer() { return serializer_reused_buffer_; }

  inline void SetGroupId(int64_t id) { group_id_ = id; }
  inline void SetBridgeFunc(std::shared_ptr<hippy::napi::CtxValue> func) {
    bridge_func_ = func;
  }
  inline void SetEngine(std::shared_ptr<Engine> engine) { engine_ = engine; }
  inline void SetScope(std::shared_ptr<Scope> scope) { scope_ = scope; }
#ifndef V8_WITHOUT_INSPECTOR
  inline void SetInspectorContext(std::shared_ptr<V8InspectorContext> inspector_context) {
    inspector_context_ = inspector_context;
  }
  inline std::shared_ptr<V8InspectorContext> GetInspectorContext() { return inspector_context_; }
#endif
  inline std::shared_ptr<TurboModuleRuntime> GetTurboModuleRuntime() {
    return turbo_module_runtime_;
  }
  inline void SetTurboModuleRuntime(
      std::shared_ptr<TurboModuleRuntime> turbo_module_runtime) {
    turbo_module_runtime_ = turbo_module_runtime;
  }

  static void Insert(const std::shared_ptr<Runtime>& runtime);
  static std::shared_ptr<Runtime> Find(int32_t id);
  static std::shared_ptr<Runtime> Find(v8::Isolate* isolate);
  static bool Erase(int32_t id);
  static bool Erase(const std::shared_ptr<Runtime>& runtime);

 private:
  bool enable_v8_serialization_;
  bool is_debug_;
  int64_t group_id_;
  std::shared_ptr<Bridge> bridge_;
  std::string serializer_reused_buffer_;
  std::shared_ptr<Engine> engine_;
  std::shared_ptr<Scope> scope_;
  std::shared_ptr<hippy::napi::CtxValue> bridge_func_;
  int32_t id_;
  std::shared_ptr<TurboModuleRuntime> turbo_module_runtime_;
#ifndef V8_WITHOUT_INSPECTOR
  std::shared_ptr<V8InspectorContext> inspector_context_;
#endif
};
