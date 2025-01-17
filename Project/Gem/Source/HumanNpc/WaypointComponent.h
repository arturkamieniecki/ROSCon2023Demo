/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root
 * of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include <AzCore/Component/Component.h>
#include <AzCore/Serialization/EditContext.h>
#include <HumanNpc/WaypointBus.h>

namespace ROS2::Demo
{
    struct WaypointConfiguration
    {
        AZ_TYPE_INFO(WaypointConfiguration, "{7b416d78-90b1-410a-a85a-835a4fc27e4a}");
        static void Reflect(AZ::ReflectContext* context);

        bool m_orientationCaptured{ false };
        float m_idleTime{ 0 };
    };

    //! Component that signifies a waypoint.
    //! The waypoint may be configured to capture its orientation
    //! (only the rotation around the z axis) or require an idle time.
    class WaypointComponent
        : public AZ::Component
        , private WaypointRequestBus::Handler
    {
    public:
        AZ_COMPONENT(WaypointComponent, "{e3acb4eb-bc11-438c-b4da-f9b4b67c7d3b}", AZ::Component);
        WaypointComponent() = default;
        ~WaypointComponent() override = default;

        // clang-format off
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required) {}
        // clang-format on
        static void Reflect(AZ::ReflectContext* context);

        // Component overrides
        void Activate() override;
        void Deactivate() override;

        // WaypointRequestBus overrides
        WaypointConfiguration GetConfiguration() override;

    private:
        WaypointConfiguration m_configuration;
    };
} // namespace ROS2::Demo
