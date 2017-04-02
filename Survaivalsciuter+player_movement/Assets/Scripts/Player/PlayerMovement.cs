using UnityEngine;

[RequireComponent (typeof(Animator))]
[RequireComponent (typeof(Rigidbody))]

public class PlayerMovement : MonoBehaviour
{
	public float speed = 6.0f;
	private Animator _anim;
	private Rigidbody _rb;

	void Awake ()
	{
		_anim = GetComponent<Animator> ();
		_rb = GetComponent<Rigidbody> ();
	}

	void FixedUpdate()
	{
		float h = Input.GetAxis ("Horizontal");
		float v = Input.GetAxis ("Vertical");

		Move (h, v);
		Rotate ();
		Animating (h, v);
	}

	private void Move(float h, float v)
	{
		transform.Translate ( (speed * Time.deltaTime)*h, 0, (speed * Time.deltaTime)*v);
	}

	private void Rotate()
	{
			_rb.rotation = Quaternion.Euler (0.0f, Input.mousePosition.x, 0.0f);
	}

	private void Animating (float h, float v)
	{
		bool walking = (h != 0 || v != 0);
		_anim.SetBool ("IsWalking", walking);
	}
}
