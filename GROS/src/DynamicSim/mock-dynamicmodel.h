class MockDynamicModel : public DynamicModel {
 public:
  MOCK_METHOD0(initModel,
      void());
  MOCK_METHOD2(integrate,
      bool(State_t* state, float timeStep));
  MOCK_METHOD2(stateDistance,
      float(State_t initState, State_t endState));
  MOCK_METHOD2(timeToTarget,
      float(State_t initState, State_t targetState));
  MOCK_METHOD2(timeToTargetSpeed,
      float(State_t initState, State_t targetState));
  MOCK_METHOD2(distanceToTargetSpeed,
      float(State_t initState, State_t targetState));
  MOCK_METHOD2(updateAcceleration,
      void(State_t* state, State_t targetState));
};
