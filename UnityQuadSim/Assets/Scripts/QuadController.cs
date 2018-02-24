using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(QuadMotor))]
public class QuadController : MonoBehaviour {

	[SerializeField] //Serialize field makes variables visible in the inspector (right hand side of Unity window)
	private float speed = 2f; //Hexadecimal speed
    [SerializeField]
    private float lookSensitivity = 3f;

	private QuadMotor motor;
	float _yMov = 0.0f; //Have to add f bc or else 0.0 is a double not a float


	// Use this for initialization
	void Start() {
		motor = GetComponent<QuadMotor>();
	}
	
	// Update is called once per frame
	void Update() {
		//Calculate movement velocity as a 3D vector
		float _xMov = Input.GetAxisRaw("Horizontal");

		//_yMove is declared above bc we do not want to reinitialize it constantly
		if(Input.GetMouseButtonDown(0)) { //Checks if left mouse button is presssed
			_yMov += 0.05f;
		}

		if(Input.GetMouseButtonDown(1)) { //Checks if right mouse button is presssed
			_yMov -= 0.05f;
		}
				
		float _zMov = Input.GetAxisRaw("Vertical");

		Vector3 movHorizontal = transform.right * _xMov * -1;
		//transform.right takes into account the relative direction of the quad
		//not just the world's right. Vector right is (1, 0, 0)
		Vector3 movY = transform.up * _yMov;
		Vector3 movVertical = transform.forward * _zMov * -1; //Vector forward is (0, 0, 1)

		Vector3 _veloctiy = (movHorizontal + movY + movVertical).normalized * speed; 
		//normalized makes sure mov only changes direction not speed

		motor.Move(_veloctiy);


        //Handles left right rotation
        float _yRot = Input.GetAxis("Mouse X");

        Vector3 _rotation = new Vector3(0f, _yRot, 0f) * lookSensitivity;

        motor.Rotate(_rotation);


	}
}
