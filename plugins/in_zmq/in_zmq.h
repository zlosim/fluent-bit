/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  ZMQ input plugin for Fluent Bit
 *  ===============================
 *  Copyright (C) 2019      The Fluent Bit Authors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef FLB_IN_ZMQ_H
#define FLB_IN_ZMQ_H

#include <czmq.h>

struct flb_input_instance;

struct flb_in_zmq_ctx {
    /* config */
    const char      *zmq_endpoint;
    int       batch_size;
    int       schedule_nanos;

    int             coll_fd;
    zsock_t         *zmq_pull_socket;
    zpoller_t       *zmq_poller;

    /* Input instance reference */
    struct flb_input_instance *i_ins;
};

#endif /* FLB_IN_ZMQ_H */
