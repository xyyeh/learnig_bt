#pragma once

#include "behaviortree_cpp_v3/behavior_tree.h"
#include "behaviortree_cpp_v3/bt_factory.h"

namespace ExampleNodes {

// Example of custom SyncActionNode (synchronous action)
// with an output port.
class ThinkWhatToSay : public BT::SyncActionNode {
 public:
  ThinkWhatToSay(const std::string& name, const BT::NodeConfiguration& config)
      : BT::SyncActionNode(name, config) {}

  // This Action simply write a value in the port "text"
  BT::NodeStatus tick() override {
    // Sets the output of type string tagged "text"
    std::cout << "Setting <text> as 'The answer is 42'" << std::endl;
    setOutput("text", "The answer is 42");
    return BT::NodeStatus::SUCCESS;
  }

  // A node having ports MUST implement this STATIC method
  static BT::PortsList providedPorts() {
    return {BT::OutputPort<std::string>("text")};
  }
};

// Example of custom SyncActionNode (synchronous action)
// with an input port.
class SaySomething : public BT::SyncActionNode {
 public:
  SaySomething(const std::string& name, const BT::NodeConfiguration& config)
      : BT::SyncActionNode(name, config) {}

  // You must override the virtual function tick()
  BT::NodeStatus tick() override;

  // It is mandatory to define this static method.
  static BT::PortsList providedPorts() {
    return {BT::InputPort<std::string>("message")};
  }
};

// Same as class SaySomething, but to be registered with SimpleActionNode
BT::NodeStatus SaySomethingSimple(BT::TreeNode& self);

}  // namespace ExampleNodes