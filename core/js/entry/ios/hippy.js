/*
 * Tencent is pleased to support the open source community by making
 * Hippy available.
 *
 * Copyright (C) 2017-2022 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// init global params, global is the top 'this'
require('../../global/Others.js');

// add global functions, do not change this order
require('../../global/DynamicLoad.js');
require('../../global/Platform.js'); // Hippy.device.platform
require('../../bridge/ios/js2native.js'); // Hippy.bridge
require('../../global/TimerModule.js'); // setTimeout clearTimeout setInterval clearInterval
require('../../global/ios/promise.js'); // add Promise when iosVersion < 9, to_do
require('../../global/ConsoleModule.js'); // console
require('../../global/UIManagerModule.js'); // document
require('../../global/Network.js'); // Headers fetch Response
require('../../global/Storage.js'); // localStorageAsync
require('../../global/Event.js'); // dealloc event
require('../../global/Dimensions.js'); // Hippy.device.window Hippy.device.screen Hippy.device.pixelRatio
require('../../global/UtilsModule.js'); // Hippy.device.vibrate Hippy.device.cancelVibrate
require('../../global/ios/global.js'); // __GLOBAL__
require('../../modules/ios/jsTimersExecution.js'); // ios module for .h build
require('../../bridge/ios/native2js.js');
require('../../global/ios/requestAnimationFrame.js'); // requestAnimationFrame cancelAnimationFrame
require('../../global/ios/Turbo.js'); // turbo
require('../../global/MemoryModule.js'); // performance.memory
// alias
global.localStorage = Hippy.asyncStorage;
global.turboPromise = Hippy.turboPromise;
