class MockDynamicSim : public DynamicSim {
 public:
  MOCK_METHOD0(init,
      void());
  MOCK_METHOD2(init,
      void(std::vector<Node> nodes,std::vector<Entity> entities));
  MOCK_METHOD1(timeToNextNode,
      float(char* entityId));
  MOCK_METHOD2(nodeDistance,
      float(short node1, short node2));
  MOCK_METHOD1(update,
      short(float timeStep));
};
