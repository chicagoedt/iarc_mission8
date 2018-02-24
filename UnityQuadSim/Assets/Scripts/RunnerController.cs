using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RunnerController : MonoBehaviour {
    [SerializeField] //Serialize field makes variables visible in the inspector (right hand side of Unity window)
    private float runnerSpeed = 5f; //Hexadecimal speed
    [SerializeField]
    private float lookSensitivity = 3f;

    private RunnerMovement runner;
    float _yMov = 0.0f; //Have to add f bc or else 0.0 is a double not a float


    // Use this for initialization
    void Start() {
        runner = GetComponent<RunnerMovement>();
    }

    // Update is called once per frame
    void Update() {
        //Calculate movement velocity as a 3D vector
        float _xMov = Input.GetAxisRaw("Horizontal");

        //_yMove is declared above bc we do not want to reinitialize it constantly
        if(Input.GetMouseButtonDown(0)) { //Checks if left mouse button is presssed
            _yMov += 0.1f;
        }

        if(Input.GetMouseButtonDown(1)) { //Checks if right mouse button is presssed
            _yMov -= 0.1f;
        }

        float _zMov = Input.GetAxisRaw("Vertical");

        Vector3 movHorizontal = transform.right * _xMov;
        //transform.right takes into account the relative direction of the quad
        //not just the world's right. Vector right is (1, 0, 0)
        Vector3 movY = transform.up * _yMov;
        Vector3 movVertical = transform.forward * _zMov; //Vector forward is (0, 0, 1)

        Vector3 _veloctiy = (movHorizontal + movY + movVertical).normalized * runnerSpeed; 
        //normalized makes sure mov only changes direction not speed

        runner.Move(_veloctiy);


        //Handles left right rotation
        float _yRot = Input.GetAxis("Mouse X");

        Vector3 _rotation = new Vector3(0f, _yRot, 0f) * lookSensitivity;

        runner.Rotate(_rotation);

        //Handles up down rotation
        float _xRot = Input.GetAxis("Mouse Y");

        Vector3 _cameraRotation = new Vector3(_xRot, 0f, 0f) * lookSensitivity;

        runner.RotateCamera(_cameraRotation);

    } 
}
