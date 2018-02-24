using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SwitchCam : MonoBehaviour {
	public Camera mainCamera;
    public Camera personCam;

	//Quad cams:
	public Camera quad0Cam;
	public Camera quad1Cam;
	public Camera quad2Cam;
	public Camera quad3Cam;

	// Use this for initialization
	void Start () {
		mainCamera.enabled = true;
        personCam.enabled = false;
		quad0Cam.enabled = false;
		quad1Cam.enabled = false;
		quad2Cam.enabled = false;
		quad3Cam.enabled = false;
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetButton("1")) {
			quad0Cam.enabled = true;
			quad1Cam.enabled = false;
			quad2Cam.enabled = false;
			quad3Cam.enabled = false;
            personCam.enabled = false;
			mainCamera.enabled = false;
		}
		if (Input.GetButton("2")) {
			quad1Cam.enabled = true;
			quad0Cam.enabled = false;
			quad2Cam.enabled = false;
            quad3Cam.enabled = false;        
            personCam.enabled = false;
			mainCamera.enabled = false;
		}
		if (Input.GetButton("3")) {
			quad2Cam.enabled = true;
			quad0Cam.enabled = false;
			quad1Cam.enabled = false;
			quad3Cam.enabled = false;
            personCam.enabled = false;
			mainCamera.enabled = false;
		}
		if (Input.GetButton("4")) {
			quad3Cam.enabled = true;
			quad0Cam.enabled = false;
			quad1Cam.enabled = false;
			quad2Cam.enabled = false;
            personCam.enabled = false;
			mainCamera.enabled = false;
        }
        if (Input.GetButton("5")) {
            personCam.enabled = true;
            mainCamera.enabled = false;
            quad0Cam.enabled = false;
            quad1Cam.enabled = false;
            quad2Cam.enabled = false;
            quad3Cam.enabled = false;

        }
		if (Input.GetButton("MainCam")) {
			mainCamera.enabled = true;
			quad0Cam.enabled = false;
			quad1Cam.enabled = false;
			quad2Cam.enabled = false;
			quad3Cam.enabled = false;
            personCam.enabled = false;

		}
	}
}
