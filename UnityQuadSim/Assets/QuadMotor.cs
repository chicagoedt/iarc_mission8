using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class QuadMotor : MonoBehaviour {

	private Vector3 veloctiy = Vector3.zero;

	private Rigidbody rb;
	// Use this for initialization
	void Start () {
		rb = GetComponent<Rigidbody> ();
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	//Gets a movement vector
	public void move (Vector3 _velocity) {
		veloctiy = _velocity; 
	}

	void FixedUpdate() {
		PerformMovement ();

	}


	void PerformMovement() {
		if (veloctiy != Vector3.zero) {
			rb.MovePosition (rb.position + veloctiy * Time.fixedDeltaTime);
		}
	}


}
