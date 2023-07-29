# Philosophers
Dining Philosophers simulation with pthreads


run with:
./philo [number of philos] [time to die] [time to eat] [time to sleep] [optional: amount to eat]

Philosophers should report their death no more that 10ms after the actual death of the philosopher

<img width="330" alt="Screen Shot 2022-10-24 at 3 39 40 PM" src="https://user-images.githubusercontent.com/26721576/197517825-e060c7d1-cb2d-4474-89a8-d67aa41ef374.png">

# Philosophers - Learning Outcomes and Reflection

The Philosophers project delved into the realm of philosophy and challenged me to create a simulation involving multiple philosophers sitting at a round table. The objective was to allow them to eat, think, and sleep while ensuring they did not starve or encounter deadly situations. The project explored the use of threads and mutexes to manage concurrency and synchronization effectively.

## Learning Outcomes
Throughout the Philosophers project, I achieved the following learning outcomes:

1. **Multithreading and Synchronization:** I gained a solid understanding of multithreading concepts and how to use threads to represent philosophers. I learned to handle synchronization issues by using mutexes to protect shared resources, such as forks, and prevent data races.

2. **Command-Line Arguments Handling:** The project required me to handle command-line arguments efficiently. I learned to parse and validate inputs to set up the simulation correctly.

3. **Handling Time and Timestamps:** I became proficient in managing time in milliseconds and generating timestamps for displaying philosopher states and events. I used this knowledge to meet the simulation's specific output requirements.

4. **Simulating a Dining Philosopher's Problem:** By modeling the problem of dining philosophers, I explored various states that a philosopher could be in, such as eating, thinking, or sleeping. I implemented the rules for their interactions and ensured they adhered to safety constraints.

5. **Avoiding Deadlocks and Starvation:** I developed strategies to avoid deadlocks and ensure that philosophers did not starve while maintaining their interactions with forks in a balanced manner.

6. **Error Handling and Debugging:** I became proficient in error handling techniques, debugging, and troubleshooting issues that arose during the development process.

## Reflection
The Philosophers project was an intellectually stimulating experience that allowed me to apply my knowledge of multithreading and synchronization in a practical setting. It taught me the importance of efficient resource management in concurrent environments and the significance of avoiding deadlocks and race conditions.

Through this project, I enhanced my problem-solving skills and learned to design robust simulations that adhere to specific requirements and constraints. Additionally, working on this project gave me a deeper appreciation for the complexities and challenges associated with managing concurrent systems.

Overall, the Philosophers project provided me with valuable insights into the world of multithreading, synchronization, and philosophy. It was a rewarding experience that further solidified my understanding of these fundamental concepts in computer science.
