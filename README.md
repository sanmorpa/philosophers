<h1>philosophers</h1>
<h2>Project description</h2>
<div>
<!--  <a href="https://github.com/JaeSeoKim/badge42">
    <img align="center" src="https://badge42.herokuapp.com/api/project/samoreno/ft_printf"/>
  </a> -->
  <p>This is a project at 42 Madrid. The aim is to learn the basics of threading a process, how to make threads and mutex. The goal is to create a program that solves he following problem:
  <ul>
    <li>One or more philosophers are sitting at a round table either eating, either thinking, either sleeping. While they are eating, they do not think or sleep; while thinking they don’t eat or sleep; and, of course, while sleeping, they do not eat or think</li>
    <li>The philosophers sit at a circular table with a large bowl of spaghetti in the center</li>
    <li>There are some forks on the table. Serving and eating spaghetti with a single fork is very inconvenient, so the philosophers will eat with two forks, one for each hand</li>
    <li>Each time a philosopher finishes eating, they will drop their forks and start sleeping. Once they have finished sleeping, they will start thinking. The simulation stops when a philosopher dies</li>
    <li>Every philosopher needs to eat and they should never starve</li>
    <li>Philosophers don’t know when another philosopher is about to die</li>
  </ul>
  The specificaations of this project are:
  <ul>
    <li>Global variables are forbidden</li>
    <li>The program should take the following arguments: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]</li>
    <ul>
      <li>number_of_philosophers: is the number of philosophers and also the number of forks</li>
      <li>time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting their last meal or the beginning of the simulation, it dies</li>
      <li>time_to_eat: is in milliseconds and is the time it takes for a philosopher to  eat. During that time they will need to keep the two forks</li>
      <li>time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping</li>
     <li> number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.</li>
    </ul>
    <li> Each philosopher should be given a number from 1 to ’number_of_philosophers’</li>
    <li>Philosopher number 1 is next to philosopher number ’number_of_philosophers’. Any other philosopher with the number N is seated between philosopher N - 1 and philosopher N + 1</li>
    <li>Any change of status of a philosopher must be written as follows (with X replaced with the philosopher number and timestamp_in_ms the current timestamp in miliseconds</li>
    <ul>
      <li>timestamp_in_ms X has taken a fork</li>
      <li>timestamp_in_ms X is eating</li>
      <li>timestamp_in_ms X is sleeping</li>
      <li>timestamp_in_ms X is thinking</li>
      <li>timestamp_in_ms X died</li>
    </ul>
    <li>There can’t be more than 10 ms between the death of a philosopher and when it will print its death</li>
  </ul>
  <table>
    <tr>
      <th>Program name</th>
      <td>philo</td>
    </tr>
    <tr>
      <th>Arguments</th>
      <td>number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]</td>
    </tr>
    <tr>
      <th>External C functions allowed</th>
      <td>memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, thread_mutex_unlock</td>
    </tr>
    <tr>
      <th>Description</th>
      <td>philosopher with threads and mutex</td>
    </tr>
</table>
  </p>
  <p>
  Finally, each philosopher should be a thread and there's one fork between each philosopher (if they are multiple philosophers, there will be a fork at the right and the left of each philosopher) and one mutex per fork.
  </p>
</div>
<h2>Usage</h2>
<div>
    <p>
        With the Makefile you can compile directly. The rules that it allows are:
        <ul>
         <li>Make: it compiles directly</li>
         <li>Make re: if the project is already compiled, it does it again</li>
         <li>Make clean. Deletes all .o files but the executable remains</li>
         <li>make fclean: deletes all .o files and the executable</li>
    </ul>
    </p>
    <p>
    Launch the program as follows:<br/>
  <b>./philos number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]</b></br>
    It is recommended you use at least 60 miliseconds for each of the times
    </p>
</div>
