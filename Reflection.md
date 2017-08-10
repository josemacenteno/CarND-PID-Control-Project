# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

# Reflection


## P-I-D components
Each component has a different effect on the behavior of the car

### P
This component is the feedback to the steering angle to try to go back to the center of the lane (make cte go to 0). The problem is that the car is heading in the wrong direction once cte approaches 0, and the steering is not changing. This produces a zig zaging in the driving behavior.

I was able to complete a full lap with a P-only controller though, so I would consider P as the main component to keep the car in the lane.


### I
In this project I added an I control, but I didn't see too much difference in the behavior compared to a PD-only controller. Small or large I actually make the system unstable. Therefore I kept a very small Ki. The fact that there is no improvemnt with I means the car is not biased or mialigned, which means a steering angle of 0 should not modify the car angle.

### D
This component helps us not overshoot when approaching the objective which corrects the zig zaging from a P-only controller. It also helps to correct disturbances. 

As soon as cte is decreasing then we steer in the opposite direction thanks to the D contribution, this helps us reach cte=0 with a small steering angle, if cte is decreasing too fast the D-control will start making the car head into a direction that slows down the correction a little bit.

When a disturbance comes into the system, the cte grows, which makes D contribute in the same direction as P to correct the curse.

## Final Values
The final PID values selected by default where calculated manually tuning with a constant throttle of 0.3.

Note you can pass exactly 3 floating values to the ./pid executable and play around with your own initialization. If nothing is passed, then the kp, ki, and kd gains are initialized to known good values obtained through manual tuning.

