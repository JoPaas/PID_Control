# CarND-Controls-PID
Johannes Paas
Self-Driving Car Engineer Nanodegree Program

---

## PID Controller

The PID contoller consists of three parts:
* The proportional P-part: This part makes the controller give a proportional reaction to the input value.
* The integrative I-part: This part integrates the input value over time and can thus compensate biases, because over time even small errors lead to a larger reaction.
* The derivative D-part: This part reacts to the change of the input value and thus dampens the system.

## Implementation

To meet the goal of the car staying on the track a PD controller was used. Since there are no apparent biases in the simulator (e.g. a lateral slope of the track), the I-part of the controller was set to 0.0. Before that I experimented with it and found that a anti wind up was useful, saturating the I-part to a tunable absolute value. This kept the vehicle from overreacting in corners.

The P-part factor Kp was found by increasing until the car oscillates around the lane center. Then the Kd factor was increased until the is a stable behavior. With iterations I was able to incresae the speed to ~24mph with Kp = 0.13, Ki = 0.0 and Kd = 0.9.

Here's a [link to my video result](https://github.com/Nervehurter/PID_Control/blob/master/output.mp4)

In the video two of the tightest corners are driven, along with a bit of straight road. I can be observed, that the car does not react in a very smooth way to control errors. I think this is related to the non linear link between control error (cte) and control value (steering angle). 

## Final Thoughts

A cascade of controllers could help minimizing oscillations by relieving the system of nonlinearities. The outter controller takes the cte and outputs a compensation angle (a course angle between the vehicles x-axis and lane center). This is fed into the inner controller and substractes the current course error (a second control error input). The output of the second controller is then a curvature with which the vahicle should turn towards the course angle setpoint. Since this relates directly (at least for kinematic vehicle models) to the steering angle, the control system will be much more stable, even with large control error inputs.
A second way to improve especially the control error when entering corners is a feed forward part, that could be derived from the road cirvature using a single track model. This would make the vehicle start steering even before a control error occurs and thus minimize cte.
