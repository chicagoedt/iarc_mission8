using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RunnerMovement : MonoBehaviour {
    
    [SerializeField]
    private Camera cam; //can't name cam camera b/c it's a keyword

    private Vector3 veloctiy = Vector3.zero;
    private Vector3 rotation = Vector3.zero;
    private Vector3 cameraRotation = Vector3.zero;

    private Rigidbody rb;
    // Use this for initialization
    void Start() {
        rb = GetComponent<Rigidbody>();
    }
    void FixedUpdate() {
        if(cam.enabled == true) {
            PerformMovement();
            PerformRotation();
        }
    }


    //Gets a movement vector
    public void Move(Vector3 _velocity) {
        veloctiy = _velocity; 
    }

    //Gets a rotation vector
    public void Rotate(Vector3 _rotation) {
        rotation = _rotation;
    }

    public void RotateCamera(Vector3 _cameraRotation) {
        cameraRotation = _cameraRotation;
    }

    //Perform movement based on velocity vector
    void PerformMovement() {
        if (veloctiy != Vector3.zero) {
            rb.MovePosition (rb.position + veloctiy * Time.fixedDeltaTime);
        }
    }

    //Perform rotation based on rotation vector
    void PerformRotation() {
        rb.MoveRotation(rb.rotation * Quaternion.Euler(rotation));
        if(cam != null) {
            cam.transform.Rotate(-cameraRotation);
        }
    }

}
