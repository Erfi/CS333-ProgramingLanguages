/*
Erfan Azad
Date: 28 November 2014
File: autoMem.java
Description: Doing eperiments with automatic garbage collection in java
*/

import java.util.*;
import java.util.ArrayList;

class autoMem{

	public void memFiller(){
		Random rand = new Random();
		ArrayList<Integer> a = new ArrayList<Integer>();
		for(int i=0; i<100; i++){
			a.add(rand.nextInt(100));
		}
	}

	public void run(){
		Timer t = new Timer();
		long maxTime = 0L;
		
		for(int j=0; j<100; j++){	
			t.start();

			memFiller();

			t.stop();
			long runTime = t.getRunTime();
			System.out.println("runtime: "+runTime+ " ms");
			if(runTime > maxTime){
				maxTime = runTime;
			}
		}
		System.out.println("\nmaxTime: "+maxTime+ " ms");
	}

	public static void main(String[] args){
		autoMem auto = new autoMem();
		auto.run();

	}
}

class Timer {
        private static long startTime;
        private static long endTime;

        public static void start(){
                startTime = System.nanoTime();
        }

        public static void stop(){
                endTime = System.nanoTime();
        }

        //gives the runtime is microseconds
        public static long getRunTime(){
                return (endTime - startTime) / 1000;
        }
}